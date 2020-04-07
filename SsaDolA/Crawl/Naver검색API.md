## Naver 검색 API를 이용한 블로그 Crawling

개발환경 우분투 서버  

1. python3 이용  

>sudo apt install python3-pip
>sudo pip3 install beautifulsoup4

2. Naver Developers 계정 생성 후 API key 받기  

>naver_client_id = "J9FEDsly6vXMqOJo4mOW"
>naver_client_secret = "XkX2x_hVkO"

<https://developers.naver.com/docs/search/blog/>

3. Crawling

아래를 많이 참고히여 crawl_api.py 작성  
<https://github.com/xotrs/naver-blog-crawler>
