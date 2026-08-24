import json
import os
import re

def clean_map_name(map_str):
    name = map_str.replace("MAP_", "")
    parts = re.split(r'(\d+)', name)
    cleaned = " ".join(p.capitalize() for p in parts if p)
    return cleaned

def parse_all_encounters():
    json_path = os.path.join("src", "data", "wild_encounters.json")
    
    if not os.path.exists(json_path):
        print(f"Could not find {json_path}. Make sure you are running this from your project root directory.")
        return

    with open(json_path, "r", encoding="UTF-8") as f:
        data = json.load(f)

    # Extract encounter rates from the group's fields header configuration
    type_rates = {}
    for group in data.get("wild_encounter_groups", []):
        for field in group.get("fields", []):
            enc_type = field.get("type")
            rates = field.get("encounter_rates", [])
            if enc_type and rates:
                type_rates[enc_type] = rates

    markdown_lines = []
    maps_data = {}

    for group in data.get("wild_encounter_groups", []):
        for encounter in group.get("encounters", []):
            base_label = encounter.get("base_label", "")
            
            # Skip entries that have FireRed or LeafGreen in their base label
            if "FireRed" in base_label or "LeafGreen" in base_label:
                continue

            map_key = encounter.get("map")
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
                    mons_list = encounter[enc_type].get("mons", [])
                    if mons_list:
                        maps_data[map_key][variant][enc_type] = mons_list

    for map_key, variants in maps_data.items():
        pretty_name = clean_map_name(map_key)
        markdown_lines.append(f"## {pretty_name}\n")
        
        for variant, types_dict in variants.items():
            for enc_type, mons in types_dict.items():
                type_label = enc_type.replace("_mons", "").replace("_", " ").capitalize()
                if enc_type == "land_mons":
                    header_title = f"{pretty_name} ({variant})"
                else:
                    header_title = f"{pretty_name} ({variant}) - {type_label}"

                markdown_lines.append(f"**{header_title}**")
                
                rates_array = type_rates.get(enc_type, [])
                
                rate_buckets = {}
                for idx, mon in enumerate(mons):
                    rate = rates_array[idx] if idx < len(rates_array) else 1
                    species_name = mon.get("species", "").replace("SPECIES_", "").lower().capitalize()
                    
                    if rate not in rate_buckets:
                        rate_buckets[rate] = []
                    if species_name not in rate_buckets[rate]:
                        rate_buckets[rate].append(species_name)
                
                sorted_rates = sorted(rate_buckets.keys(), reverse=True)
                
                for rate in sorted_rates:
                    species_joined = ", ".join(rate_buckets[rate])
                    markdown_lines.append(f"*{rate}%:-*")
                    markdown_lines.append(species_joined)
                
                markdown_lines.append("")
        
        markdown_lines.append("")

    with open("wild_encounterinfo.md", "w", encoding="UTF-8") as f:
        f.write("\n".join(markdown_lines))
    
    print("Successfully generated wild_encounterinfo.md from src/data/wild_encounters.json!")

if __name__ == "__main__":
    parse_all_encounters()