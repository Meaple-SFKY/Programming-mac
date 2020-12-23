from selenium import webdriver
import pandas as pd
from urllib import parse
import time
import requests
from lxml import etree
import urllib.parse
import csv

# url = "https://www.aqistudy.cn/historydata/"
# response = requests.get(url)
# text = response.content.decode('utf-8')
# html = etree.HTML(text)
city = '合肥'

driver = webdriver.PhantomJS(
    r'/usr/local/Caskroom/phantomjs/2.1.1/phantomjs-2.1.1-macosx/bin/phantomjs')
base_url = 'https://www.aqistudy.cn/historydata/monthdata.php?city='

print(city)
weburl = ('%s%s' % (base_url, parse.quote(city)))
print(weburl)
driver.get(weburl)
time.sleep(1)
dfs = pd.read_html(driver.page_source, header=0)[0]
time.sleep(0.5)
driver.quit()
print('🌚Enjoy!')

dfs.drop(['范围'], axis=1, inplace = True)
aqi = dfs['AQI']
grade = dfs['质量等级']
dfs.drop(labels = ['AQI'], axis = 1, inplace = True)
dfs.drop(labels = ['质量等级'], axis = 1, inplace = True)
dfs.insert(dfs.shape[1], 'AQI', aqi)
dfs.insert(dfs.shape[1], '质量等级', grade)

print(dfs)
dfs.to_csv(r'/Users/sfky/Documents/Programming/Python_Folder/ML/data/%s.csv' %
           (str(city)), index=False)
