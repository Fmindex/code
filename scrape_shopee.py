from selenium import webdriver
from selenium.webdriver.chrome.options import Options


def get_data(URL):
  
  options = Options()
  options.headless = True
  options.add_argument("--window-size=1920,1200")
  DRIVER_PATH = './chromedriver'
  driver = webdriver.Chrome(options=options, executable_path=DRIVER_PATH)
  driver.get(URL)
  # print(driver.page_source)
  driver.set_window_size(1920, 108000)
  # driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
  fm = driver.find_elements_by_class_name('shop-search-result-view__item')
  # print(len(fm), fm)
  sum = 0.0
  for c in fm:
    val = float(c.find_elements_by_class_name('_341bF0')[0].text.replace(",", ""))
    sum += val
  print("avg: {0} \ncount: {1}\n".format(sum / len(fm), len(fm)))
  #main > div > div.shopee-page-wrapper > div.shop-search-page.container > div > div.shop-search-page__right-section > div > div.shop-search-result-view > div > div:nth-child(24) > div > a > div > div._3eufr2 > div._2lBkmX > div._1w9jLI._37ge-4._2ZYSiu > span._341bF0
  driver.quit()

  data='f'


URL = 'https://shopee.co.th/shop/168093522/search?page=2&sortBy=pop'
get_data(URL)
