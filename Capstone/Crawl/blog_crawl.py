# -*- coding: utf-8 -*-
import re
import json
import math
import datetime
import requests
import urllib.request
import urllib.error
import urllib.parse
from bs4 import BeautifulSoup
import unicodecsv as csv
import pandas as pd
from pandas import DataFrame

naver_client_id = "J9FEDsly6vXMqOJo4mOW"
naver_client_secret = "XkX2x_hVkO"
class naver_blog_crawling:
    def __init__(self,keyword,num,sort):
        self.search_blog_keyword = keyword
        self.display_count = num
        self.sort_type = sort
    def get_blog_post(self,i):
        iter = i
        encode_search_keyword = urllib.parse.quote(self.search_blog_keyword)
        url = "https://openapi.naver.com/v1/search/blog?query=" + encode_search_keyword +  "&display=" + str(
            self.display_count) + "&start=" + str(i) + "&sort=" + self.sort_type
        request = urllib.request.Request(url)

        request.add_header("X-Naver-Client-Id", naver_client_id)
        request.add_header("X-Naver-Client-Secret", naver_client_secret)

        response = urllib.request.urlopen(request)
        response_code = response.getcode()

        if response_code is 200:
            response_body = response.read()
            response_body_dict = json.loads(response_body.decode('utf-8'))
            post_list = []

            for j in range(0, len(response_body_dict['items'])):
                try:
                    blog_post_url = response_body_dict['items'][j]['link'].replace("amp;", "")

                    get_blog_post_content_code = requests.get(blog_post_url)
                    get_blog_post_content_text = get_blog_post_content_code.text

                    get_blog_post_content_soup = BeautifulSoup(get_blog_post_content_text, 'lxml')

                    for link in get_blog_post_content_soup.select('#mainFrame'):
                        real_blog_post_url = "http://blog.naver.com" + link.get('src')

                        get_real_blog_post_content_code = requests.get(real_blog_post_url)
                        get_real_blog_post_content_text = get_real_blog_post_content_code.text

                        get_real_blog_post_content_soup = BeautifulSoup(get_real_blog_post_content_text, 'lxml')
                       
                        test = get_real_blog_post_content_soup.select('#postViewArea')
                        if not test:
                            blog_post_content_text=[]
                            for blog_post_content in get_real_blog_post_content_soup.select('div.se_textview'):
                                blog_post_content_text.append(blog_post_content.get_text())
                        if test:
                            blog_post_content_text = get_real_blog_post_content_soup.select('#postViewArea')[0].get_text()
                        
                        remove_html_tag = re.compile('<.*?>')
                        blog_post_title = re.sub(remove_html_tag, '', response_body_dict['items'][j]['title'])
                        blog_post_description = re.sub(remove_html_tag, '',
                                                           response_body_dict['items'][j]['description'])
                        blog_post_postdate = datetime.datetime.strptime(response_body_dict['items'][j]['postdate'],
                                                                            "%Y%m%d").strftime("%y.%m.%d")
                        blog_post_full_contents = str(blog_post_content_text)
                        post_list.append({'URL':blog_post_url,'title' : blog_post_title, 'date': blog_post_postdate,'text':blog_post_full_contents})
                        print(iter)
                        iter = iter+1
                except:
                    j += 1
        print("[*] Complete Crawling")
        return post_list
if __name__ == '__main__':
    keyword = input("검색 : ")
    crawling = naver_blog_crawling(keyword,100,"sim")
    data = crawling.get_blog_post(1)
    dt = pd.DataFrame(data)
    data2 = crawling.get_blog_post(101)
    dt2 = pd.DataFrame(data2)
    data3 = crawling.get_blog_post(201)
    dt3 = pd.DataFrame(data3)

    dt = dt.append(dt2,ignore_index=True)
    dt = dt.append(dt3,ignore_index=True)

    filename = input("저장할 이름: ")
    filename = filename + ".csv"
    dt.to_csv(filename,encoding="utf-8-sig",index=False)
