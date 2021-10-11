import smtplib
import time
import os

from selenium import webdriver
from selenium.webdriver.support.ui import Select

# Declare e-mail and password variables
EMAIL_NAME = os.environ.get("EMAIL_NAME")
EMAIL_PASS = os.environ.get("EMAIL_PASS")
USER_NAME = os.environ.get("USER_NAME")
USER_ID = os.environ.get("USER_ID")
SEND_TO_EMAIL_ADDRESS = os.environ.get("SEND_TO_EMAIL_ADDRESS")
USER_PATH = os.environ.get("USER_PATH")
refresh_counter = 0

webpage = r"https://www.dcs.co.il/check-request"


def enter_to_my_area(driver):
    """
    This Function Will Enter To My Personal Area And Return The Current Status Of My MacBook
    """

    # from dropdown list, select "Apple"
    time.sleep(3)   # wait for 3 seconds for all elements in the page to load correctly
    select = Select(driver.find_element_by_xpath('//*[@id="comp-khz5u53pcollection"]'))
    select.select_by_visible_text('Apple')
    print(f"{refresh_counter} - List Item Found")

    # input to fields my credentials
    driver.find_element_by_xpath('//*[@id="input_comp-kfv34f31"]').send_keys(USER_NAME)
    driver.find_element_by_xpath('//*[@id="input_comp-kfv3au7a"]').send_keys(USER_ID)
    print(f"{refresh_counter} - Sent User Keys")

    time.sleep(2)   # wait for 2 seconds for the site to check the fields and make the 'submit' button clickable

    # click on submit button
    driver.find_element_by_xpath('//*[@id="comp-kfv34f2n"]').click()
    print(f"{refresh_counter} - Submit Button Clicked")

    # get status text
    return driver.find_element_by_xpath('//*[@id="comp-kfv34f9g"]/p/span/span/span').get_attribute("innerText")


def send_email():
    with smtplib.SMTP('smtp.gmail.com', 587) as smtp:
        smtp.ehlo()
        smtp.starttls()
        smtp.ehlo()

        smtp.login(EMAIL_NAME, EMAIL_PASS)
        subject = "MacBook's Status Change"
        body = "Your MacBook's Status Has Changed, Go And Check It Out! :)"
        msg = f'Subject: {subject}\n\n{body}'
        smtp.sendmail(EMAIL_NAME, SEND_TO_EMAIL_ADDRESS, msg)
        print("change detected, email sent")


def start_web_driver(webpage):
    """
    This Function Will Start The WebDriver And Open A Web Page
    """

    driver = webdriver.Chrome(USER_PATH)
    driver.get(webpage)
    driver.implicitly_wait(3)  # wait 3 seconds before doing another action, for the page to load well
    return driver


# start web driver (open chrome browser)
driver = start_web_driver(webpage)

# get the default status from the page
default_status = enter_to_my_area(driver)
driver.refresh()
refresh_counter += 1

while True:
    status = enter_to_my_area(driver)

    # if the status changed form default state, send me an e-mail
    if status != default_status:
        send_email()
        break

    # else if status didn't change, refresh after 1 hour and check status again
    # also print how many times the page got refreshed (for debugging purposes)
    time.sleep(3600)
    driver.refresh()
    print(f"Doing Refresh Number: {refresh_counter}")
    refresh_counter += 1
