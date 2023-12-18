import requests
from bs4 import BeautifulSoup
import os

def download_file(url, folder):
    # ファイル名をURLから抽出
    filename = url.split('/')[-1]
    path = os.path.join(folder, filename)

    # ファイルをダウンロードして保存
    response = requests.get(url)
    with open(path, 'wb') as file:
        file.write(response.content)

def download_html_and_css(url, folder='downloaded_files'):
    # ダウンロードフォルダを作成
    if not os.path.exists(folder):
        os.makedirs(folder)

    # HTMLをダウンロード
    response = requests.get(url)
    html = response.text

    # HTMLを解析
    soup = BeautifulSoup(html, 'html.parser')
    links = soup.find_all('link', {'rel': 'stylesheet'})

    # CSSファイルのURLを見つけてダウンロード
    for link in links:
        href = link.get('href')
        if href.startswith('http'):
            download_file(href, folder)
        else:
            # 相対パスの場合は絶対パスに変換
            href = requests.compat.urljoin(url, href)
            download_file(href, folder)

    return html

# 例としてGoogleのトップページをダウンロード
html_content = download_html_and_css('https://www.google.com')