import requests
from bs4 import BeautifulSoup

def scrape_and_append(url, filename):
    try:
        # Send a GET request to the URL
        response = requests.get(url)
        response.raise_for_status()  # Check if the request was successful

        # Parse the HTML content using BeautifulSoup
        soup = BeautifulSoup(response.content, 'html.parser')

        # Extract all text from the webpage
        page_text = soup.get_text(separator='\n', strip=True)

        # Open the file in append mode and write the text
        with open(filename, 'a', encoding='utf-8') as file:
            file.write(page_text + '\n\n')  # Add some space between pages

        print(f"Text from {url} has been appended to {filename}.")

    except requests.exceptions.RequestException as e:
        print(f"An error occurred while fetching the page: {e}")

# Example usage
if __name__ == "__main__":
    url = input("Enter the URL of the webpage: ")
    filename = "scraped_texts.txt"  # You can change this to any file name
    scrape_and_append(url, filename)
