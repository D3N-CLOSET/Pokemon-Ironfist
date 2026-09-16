import json
import os

def update_encounter_labels():
    json_path = os.path.join("src", "data", "wild_encounters.json")
    
    if not os.path.exists(json_path):
        print(f"Could not find {json_path}. Make sure you are running this from your project root directory.")
        return

    with open(json_path, "r", encoding="UTF-8") as f:
        data = json.load(f)

    time_suffixes = ("_Day", "_Night", "_Morning", "_Evening")

    for group in data.get("wild_encounter_groups", []):
        encounters = group.get("encounters", [])
        new_encounters = []
        
        # Track existing base labels to check for existing time variants easily
        existing_labels = {enc.get("base_label") for enc in encounters}

        for encounter in encounters:
            base_label = encounter.get("base_label", "")
            
            # Only target maps that start with gRoute, or include City, Town, Jungle, Silver, or Mountains
            is_target = base_label.startswith("gRoute") or any(k in base_label for k in ["City", "Town", "Jungle", "Silver", "Mountains", "Safari", "Underwater", "Cave", "Meteor", "Woods", "Sage", "Flower"])
            if not is_target:
                new_encounters.append(encounter)
                continue

            # Skip entries that have FireRed, LeafGreen, or end with other time suffixes (we want to process from Day)
            if "FireRed" in base_label or "LeafGreen" in base_label or base_label.endswith(("_Night", "_Morning", "_Evening")):
                new_encounters.append(encounter)
                continue

            # Check specifically if it already ends with _Day
            if base_label.endswith("_Day"):
                print(f"{base_label} already has Day format")
            else:
                # Check if it ends with any other valid time-of-day suffix
                has_time_suffix = base_label.endswith(time_suffixes)

                # If it doesn't have any time suffix, append _Day
                if not has_time_suffix:
                    base_label = base_label + "_Day"
                    encounter["base_label"] = base_label
                    print(f"Updated base_label to: {base_label}")

            new_encounters.append(encounter)

            # Now check if corresponding Night, Morning, and Evening tables exist for this Day-formatted map
            if base_label.endswith("_Day"):
                prefix = base_label[:-4]
                
                # Check Night
                night_label = prefix + "_Night"
                if night_label not in existing_labels:
                    night_encounter = encounter.copy()
                    night_encounter["base_label"] = night_label
                    new_encounters.append(night_encounter)
                    existing_labels.add(night_label)
                    print(f"Added Night table to {night_label} because it didn't have one")
                else:
                    print(f"{night_label} already has Night format")

                # Check Morning
                morning_label = prefix + "_Morning"
                if morning_label not in existing_labels:
                    morning_encounter = encounter.copy()
                    morning_encounter["base_label"] = morning_label
                    new_encounters.append(morning_encounter)
                    existing_labels.add(morning_label)
                    print(f"Added Morning table to {morning_label} because it didn't have one")
                else:
                    print(f"{morning_label} already has Morning format")

                # Check Evening
                evening_label = prefix + "_Evening"
                if evening_label not in existing_labels:
                    evening_encounter = encounter.copy()
                    evening_encounter["base_label"] = evening_label
                    new_encounters.append(evening_encounter)
                    existing_labels.add(evening_label)
                    print(f"Added Evening table to {evening_label} because it didn't have one")
                else:
                    print(f"{evening_label} already has Evening format")

        group["encounters"] = new_encounters

    # Save the modified JSON back out
    with open(json_path, "w", encoding="UTF-8") as f:
        json.dump(data, f, indent=2)
    
    print("Successfully finished processing route, city, town, and custom area base_labels and all time tables!")

if __name__ == "__main__":
    update_encounter_labels()