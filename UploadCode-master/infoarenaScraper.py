import requests
from bs4 import BeautifulSoup
import os

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.support.ui import Select
from selenium.common.exceptions import *

def pressbutton(url, driver):
    driver.get(url)

    try:
        # Wait for the button to become clickable
        button = WebDriverWait(driver, 1).until(
            EC.element_to_be_clickable((By.ID, "force_view_source"))
        )

        # Click the button
        button.click()

        # Wait for the page to load after the button click
        WebDriverWait(driver, 1).until(EC.url_contains(url))
    except TimeoutException:
        pass

    # Extract the content of the page after the button click
    new_page_content = driver.page_source

    soup = BeautifulSoup(new_page_content, 'html.parser')
    for match in soup.findAll('span'):
        match.unwrap()

    code_tag = soup.find('pre')
    code = code_tag.text.strip()

    problem_id = soup.find('a', href=lambda href: href and '/problema/' in href).text
    current_directory = os.getcwd()

    path = f'Infoarena/{problem_id}'

    final_directory = os.path.join(current_directory, path)

    if not os.path.exists(final_directory):
        os.makedirs(final_directory)
    else:
        print("Already Solved!")
        return

    with open(f'{path}/{problem_id.lower()}.cpp', 'w') as f:
        f.write(code)

    print("Problem Added!")

def get_code(url):
    page = requests.get(url)
    soup = BeautifulSoup(page.content, 'html.parser')

    code_tag = soup.find('pre')
    code = code_tag.text.strip()

    problem_id = soup.find('a', href=lambda href: href and '/problema/' in href).text
    current_directory = os.getcwd()

    path = f'Infoarena/{problem_id}'

    final_directory = os.path.join(current_directory, path)

    if not os.path.exists(final_directory):
        os.makedirs(final_directory)
    else:
        print("Already Solved!")
        return
    with open(f'{path}/{problem_id.lower()}.cpp', 'w') as f:
        f.write(code)

    print("Problem Added!")

def main():
    options = Options()
    options.add_argument('headless')
    options.add_argument('window-size=1920x1080')
    options.add_argument('disable-gpu')

    driver = webdriver.Chrome(ChromeDriverManager().install(), options=options)
    # driver = webdriver.Chrome()
    url = ''
    while url != 'exit':
        url = input('Source url:')
        try:
            get_code(url)
        except AttributeError:
            pressbutton(url, driver)
    driver.quit()

if __name__ == '__main__':
    main()
