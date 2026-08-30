import os
import re

def clean_move_name(move_str):
    # Convert macro name like FOCUS_PUNCH to Title Case like Focus Punch
    return " ".join(word.capitalize() for word in move_str.lower().split("_"))

def parse_tms_and_hms():
    header_path = os.path.join("include", "constants", "tms_hms.h")
    
    if not os.path.exists(header_path):
        print(f"Could not find {header_path}. Make sure you are running this from your project root directory.")
        return

    with open(header_path, "r", encoding="UTF-8") as f:
        content = f.read()

    # Helper function to extract macro arguments inside a given FOREACH block
    def extract_macro_block(block_name):
        pattern = rf"#define\s+{block_name}\(F\)\s*\\\s*(.*?)(?=\n\n|\n#define|\Z)"
        match = re.search(pattern, content, re.DOTALL)
        if not match:
            return []
        
        block_text = match.group(1)
        # Find all F(MOVE_NAME) occurrences
        moves = re.findall(r'F\(([A-Z0-9_]+)\)', block_text)
        return moves

    tms = extract_macro_block("FOREACH_TM")
    hms = extract_macro_block("FOREACH_HM")

    markdown_lines = []

    # Format TMs section
    markdown_lines.append("## TMs:-")
    markdown_lines.append("")
    
    for idx, tm in enumerate(tms, start=1):
        tm_num = f"TM{idx:02d}"
        formatted_name = clean_move_name(tm)
        markdown_lines.append(f"**{tm_num}** = {formatted_name},")
        markdown_lines.append("")

    markdown_lines.append("")

    # Format HMs section
    markdown_lines.append("## HMs:-")
    markdown_lines.append("")
    
    for idx, hm in enumerate(hms, start=1):
        hm_num = f"HM{idx:02d}"
        formatted_name = clean_move_name(hm)
        markdown_lines.append(f"**{hm_num}** = {formatted_name},")
        markdown_lines.append("")

    with open("tms_and_hms.md", "w", encoding="UTF-8") as f:
        f.write("\n".join(markdown_lines))
    
    print("Successfully generated tms_and_hms.md!")

if __name__ == "__main__":
    parse_tms_and_hms()