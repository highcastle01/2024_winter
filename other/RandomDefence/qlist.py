import requests
import re
import random
from bs4 import BeautifulSoup
import json
import os
from itertools import zip_longest
def find_question(levels, use_questions=[]):
    find_questions = []
    last_page = None

    #문제별로 페이지수가 달라서 마지막 페이지 찾기.
    for page in range(1, 50):
        soup = BeautifulSoup(requests.get(f"https://solved.ac/problems/level/{levels}/?page={page}").content,
                             'html.parser')

        no_problem_message = soup.find_all('div', class_='css-152w63m')
        if no_problem_message:
            break

        last_page = page
    print(last_page) #페이지 제대로 가는지 체크

    #페이지에서 텍스트(문제번호 불러오기)
    for page in range(1, last_page + 1):
        soup = BeautifulSoup(requests.get(f"https://solved.ac/problems/level/{levels}/?page={page}").content,
                             'html.parser')
        elements = soup.find_all('a', class_='css-q9j30p')
        people = soup.find_all(class_='css-1ujcjo0')

        for element, person in zip_longest(elements, people):
            question = element.get_text(strip=True)
            man_text = person.get_text(strip=True)
            man = re.sub(r'[^\d]', '', man_text)
            man = int(man)
            if(man < 500):
                continue
            match = re.search(r'\d+', question)
            if match and int(match.group()) > 1000 and match.group() not in use_questions and man > 1000:
                number = match.group()
                find_questions.append(number)

    return find_questions

def select_question(levelStart, levelEnd, use_questions=[]):
    select_questions = []

    #레벨 별로 한문제씩 넣기
    for levels in range(levelStart, levelEnd + 1):
        questions = find_question(levels, use_questions)
        random_index = random.randint(0, len(questions) - 1)
        select_questions.append(questions[random_index])

    print("Selected questions:", select_questions)

    return select_questions

def write_to_json(filename, data):
    with open(filename, 'a') as f:
        json.dump(data, f)
        f.write('\n')

def makeQ(levelStart, levelEnd):

    if not os.path.isfile('data.json'):
        with open('data.json', 'w') as f:
            f.write('[]\n')

    use_questions = []

    # JSON 파일에서 이전에 선택된 질문 읽어오기
    with open('data.json', 'r') as f:
        for line in f:
            use_questions.extend(json.loads(line))
    use_questions = list(set(use_questions))
    selected_questions = select_question(levelStart, levelEnd, use_questions)
    write_to_json('data.json', selected_questions)

    return selected_questions

#레벨 / 페이지 넘어가며 한문제씩 골라서 리스트에 넣고 json 저장.

#레벨/페이지 이렇게 가지만 우선 페이지로 다 긁어오고(파인드에서) 거기서 선별하는게 좋을 듯? 그러니까.. 페이지
