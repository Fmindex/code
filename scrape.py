import requests
from bs4 import BeautifulSoup
# import re
import json

def get_devto_data(URL):
  page = requests.get(URL)
  soup = BeautifulSoup(page.content, 'html.parser')
  results = soup.find(id='article-body')
  article_id = results.get('data-article-id')

  results = soup.find(class_='crayons-article__header__meta').find('h1')
  title = results.text.strip()

  results = soup.find(class_='crayons-article__subheader').find('time')
  published_time = results['datetime']

  results = soup.find(id='comment-trees-container').findAll('details')
  comments = len(results)

  res = requests.get('https://dev.to/reactions?article_id={}'.format(article_id))
  stat = res.json()['article_reaction_counts']

  data = {
    'url': URL,
    'title': title,
    'published_time': published_time,
    'comments': comments,
    'stat': {
      'like': stat[0]['count'],
      'readingList': stat[1]['count'],
      'unicorn': stat[2]['count']
    }
  }
  return data

def get_medium_data(url):
  page = requests.get(url)
  soup = BeautifulSoup(page.content, 'html.parser')
  title = soup.findAll('meta',  {"property" : "og:title"})[0]['content']
  # published_at = soup.findAll('meta',  {"property" : "article:published_time"})[0]['content']
  results = soup.findAll('script',  {"type" : "application/ld+json"})[0]
  published_at = json.loads(results.text)['datePublished']
  results = soup.find_all('button')
  target = ''
  for result in results:
    if 'claps' in result.text:
      target = result.text
  target = target.strip().split(" ")[0]
  print(target)
  claps = ""
  for i in target:
    if i in "0123456789KM":
      claps += i
  print(claps)
  if 'K' in claps:
    claps = int(claps[:-1]) * 1000
  else:
    claps = int(claps)
  results = soup.find_all('span')
  target = "See Response (0)"
  for result in results:
    if 'See responses' in result.text:
      target = result.text
  responses = int(target.split(" ")[2][1:-1])
  
  data = {
    'url': url,
    'title': title,
    'claps': claps,
    'responses': responses,
    'published_at': published_at
  }
  return data
  
# DEV_TO_URL = 'https://dev.to/jess/what-was-your-win-this-week-250n'
# print(get_devto_data(DEV_TO_URL))

MEDIUM_URL = 'https://medium.com/@mr.vibhorchaudhary/impressive-github-profile-readme-606e3b7b075d'
print(get_medium_data(MEDIUM_URL))

# TODO
# - implement for dev.to -DONE
# - handle error for medium and dev.to endpoint (for plugin)

# step to test
# - CRUD Event - DONE
# - Run script to save stat  - DONE
# - Run plugin and try to save medium 
# - request help from nilansh to test Celery