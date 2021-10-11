# My MacBook Got Broke! :computer:

### So to track after the repair status, I decided to build a program which runs on the background, and sends me an e-mail whenever his status is changing.

#### :books: Libraries I worked with: 	
1. smtplib (for e-mail sending)
2. selenium (for web-scraping)

#### Summary:
The program will enter the repair page, input all my details and check for the default status, then, it'll refresh the page and check every hour if the default status has changed, if not it'll continue running, if a change was detected, the program will send me an e-mail that a change detected and terminate

#### How to run the program:
Just change `EMAIL_NAME, EMAIL_PASS, USER_NAME, USER_ID, SEND_TO_EMAIL_ADDRESS, USER_PATH` to your own credentials and delete the declarations.
I used OS environment variables for security reasons.
