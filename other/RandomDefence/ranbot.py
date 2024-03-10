from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import requests
import time
from qlist import makeQ
def get_inputs(key):
    if (key == '0차'):
        return "1차", "2024-03-04 16:00", "2024-03-11 00:00"
    elif(key == '1차'):
        return "1차", "2024-03-11 00:01", "2024-03-18 00:00"
    elif(key == '2차'):
        return "2차", "2024-03-18 00:01", "2024-03-25 00:00"
    elif(key == '3차'):
        return "3차", "2024-03-25 00:01", "2024-04-01 00:00"
    elif (key == '4차'):
        return "4차", "2024-04-01 00:01", "2024-04-08 00:00"

key = input("차수 : ")
level = input("과정 : ")

########## 문제 찾기 ##########

selected_questions = []

if(level == "초급"):
    selected_questions = makeQ(1, 8)
elif(level == "중급"):
    selected_questions = makeQ(9, 15)

result = get_inputs(key)

title, start, end = result

########## 입력 #########

user_id = ""
user_pw = ""

#### 아이디 숨기기.. ####

use_date = []

driver = webdriver.Chrome()
driver.get("https://www.acmicpc.net/login?next=%2F")

driver.get("https://www.acmicpc.net/login?next=%2F")

driver.implicitly_wait(10)

driver.find_element(By.NAME,'login_user_id').send_keys(user_id)
driver.find_element(By.NAME, 'login_password').send_keys(user_pw)
driver.find_element(By.XPATH,'//*[@id="submit_button"]').click()
s = requests.Session()
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36'}
s.headers.update(headers)

##### 새창 열기 #####

time.sleep(20)
driver.execute_script("window.open('');")
driver.switch_to.window(driver.window_handles[1])
driver.get('https://www.acmicpc.net/group/practice/create/3393')

##### 연습창 입력 #####

driver.find_element(By.NAME, 'contest_title').send_keys(f'{level}랜덤디펜스 {title}')
driver.find_element(By.NAME, "contest_start").clear()
driver.find_element(By.NAME, "contest_start").send_keys(start)
driver.find_element(By.NAME, "contest_end").clear()
driver.find_element(By.NAME, "contest_end").send_keys(end)

for q in selected_questions:
    problem = driver.find_element(By.NAME, "problem_id")
    problem.clear()
    problem.send_keys(q)
    problem.send_keys(Keys.ENTER)
    driver.implicitly_wait(10)

input("Press Enter to close the browser...")
