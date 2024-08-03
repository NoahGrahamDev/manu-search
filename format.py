import re

def format_hebrew_verses(input_file, output_file):
    current_book = ""
    with open(input_file, 'r', encoding='utf-8') as infile, open(output_file, 'w', encoding='utf-8') as outfile:
        for line in infile:
            line = line.strip()
            
            # Check if it's a book title
            if "Hebrew Old Testament - " in line:
                current_book = line.split('-')[-1].strip()
                continue
            
            # Confirm book title
            if line == current_book:
                continue
            
            # Check if it's a verse
            verse_match = re.match(r'(\d+:\d+)\s(.+)', line)
            if verse_match:
                verse_number, verse_text = verse_match.groups()
                formatted_line = f"{current_book} {verse_number} {verse_text}\n"
                outfile.write(formatted_line)

# Usage
input_file = 'scraped_texts.txt'  # Replace with your input file name
output_file = 'formatted_hebrew.txt'  # Replace with your desired output file name

format_hebrew_verses(input_file, output_file)
print(f"Formatted Hebrew verses have been written to {output_file}")