import json
import os
import re

def clean_map_name(map_str):
    name = map_str.replace("MAP_", "").replace("_", " ")
    name = re.sub(r'([A-Za-z])(\d)', r'\1 \2', name)
    return " ".join(word.capitalize() for word in name.split())

def parse_all_encounters():
    json_path = os.path.join("src", "data", "wild_encounters.json")
    
    if not os.path.exists(json_path):
        print(f"Could not find {json_path}. Make sure you are running this from your project root directory.")
        return

    with open(json_path, "r", encoding="UTF-8") as f:
        data = json.load(f)

    type_rates = {}
    type_groups = {}
    
    for group in data.get("wild_encounter_groups", []):
        for field in group.get("fields", []):
            enc_type = field.get("type")
            rates = field.get("encounter_rates", [])
            groups = field.get("groups", {})
            if enc_type and rates:
                type_rates[enc_type] = rates
            if enc_type and groups:
                type_groups[enc_type] = groups

    markdown_lines = []
    maps_data = {}

    ignored_maps = {"MAP_CRESTAN_TOWN", "MAP_SILVER_ISLAND_DEPTHS_3"}

    for group in data.get("wild_encounter_groups", []):
        for encounter in group.get("encounters", []):
            base_label = encounter.get("base_label", "")
            map_key = encounter.get("map", "Valley")
            
            if "FireRed" in base_label or "LeafGreen" in base_label or map_key in ignored_maps:
                continue

            if not map_key:
                continue
            
            variant = "Day"
            if "_Night" in base_label:
                variant = "Night"
            elif "_Morning" in base_label:
                variant = "Morning"
            elif "_Evening" in base_label:
                variant = "Evening"

            if map_key not in maps_data:
                maps_data[map_key] = {}

            if variant not in maps_data[map_key]:
                maps_data[map_key][variant] = {}

            for enc_type in ["land_mons", "water_mons", "rock_smash_mons", "fishing_mons"]:
                if enc_type in encounter:
                    section_data = encounter[enc_type]
                    mons_list = section_data.get("mons", [])
                    enc_rate = section_data.get("encounter_rate", 0)
                    if mons_list:
                        maps_data[map_key][variant][enc_type] = {
                            "encounter_rate": enc_rate,
                            "mons": mons_list
                        }

    for map_key, variants in maps_data.items():
        pretty_name = clean_map_name(map_key)
        markdown_lines.append(f"## {pretty_name}\n")
        
        for variant, types_dict in variants.items():
            for enc_type, section_info in types_dict.items():
                type_label = enc_type.replace("_mons", "").replace("_", " ").capitalize()
                if enc_type == "land_mons":
                    header_title = f"{pretty_name} ({variant})"
                else:
                    header_title = f"{pretty_name} ({variant}) - {type_label}"

                enc_rate = section_info["encounter_rate"]
                mons = section_info["mons"]

                markdown_lines.append(f"**{header_title}**")
                markdown_lines.append(f"ENCOUNTER RATE: {enc_rate}")
                markdown_lines.append("```")
                
                rates_array = type_rates.get(enc_type, [])
                groups_dict = type_groups.get(enc_type, {})
                
                # Build an index-to-rod mapping for fishing or grouped encounters
                idx_to_group = {}
                for rod_name, indices in groups_dict.items():
                    formatted_rod = rod_name.replace("_", " ")
                    for idx in indices:
                        idx_to_group[idx] = formatted_rod

                rate_buckets = {}
                level_info = []

                for idx, mon in enumerate(mons):
                    rate = rates_array[idx] if idx < len(rates_array) else 1
                    species_raw = mon.get("species", "")
                    species_name = species_raw.replace("SPECIES_", "").lower().capitalize()
                    
                    min_lv = mon.get("min_level")
                    max_lv = mon.get("max_level")
                    
                    if min_lv == max_lv:
                        lv_str = f"lv {min_lv}"
                    else:
                        lv_str = f"lv {min_lv}-{max_lv}"
                    
                    level_info.append(f"{species_name}: {lv_str}")

                    # If this encounter type has group labels (like fishing rods), print sequentially with the label
                    if enc_type == "fishing_mons" and idx in idx_to_group:
                        rod_label = idx_to_group[idx]
                        markdown_lines.append(f"{rate}%: {species_name} ({rod_label})")
                    else:
                        if rate not in rate_buckets:
                            rate_buckets[rate] = []
                        if species_name not in rate_buckets[rate]:
                            rate_buckets[rate].append(species_name)
                
                # If it wasn't a grouped encounter type, output the bucketed summary rates
                if enc_type != "fishing_mons":
                    sorted_rates = sorted(rate_buckets.keys(), reverse=True)
                    for rate in sorted_rates:
                        species_joined = ", ".join(rate_buckets[rate])
                        markdown_lines.append(f"{rate}%: {species_joined}")
                
                markdown_lines.append("```")
                markdown_lines.append("Levels:")
                markdown_lines.append("```")
                for lv_line in level_info:
                    markdown_lines.append(lv_line)
                markdown_lines.append("```")
                markdown_lines.append("")

        markdown_lines.append("")
        markdown_lines.append("")

    with open("wild_encounterinfo.md", "w", encoding="UTF-8") as f:
        f.write("\n".join(markdown_lines))
    
    print("Successfully generated wild_encounterinfo.md with encounter rates and level summaries!")

if __name__ == "__main__":
    parse_all_encounters()