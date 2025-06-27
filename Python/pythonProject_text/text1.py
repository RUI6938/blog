import requests
from bs4 import BeautifulSoup
import time # 引入 time 模块，用于添加延时

# --- 合法性与道德声明 ---
# 本示例代码用于从 'quotes.toscrape.com' 网站进行数据抓取。
# 该网站是专门为网络爬虫教学目的而设计，明确允许抓取，因此是合法的实践。
#
# 在进行任何实际的网络爬虫操作时，请务必遵守以下原则：
# 1. 尊重网站的 robots.txt 文件：该文件通常位于网站根目录，例如 'https://example.com/robots.txt'，
#    它会告诉爬虫哪些部分允许访问，哪些不允许。
# 2. 查阅并遵守网站的服务条款 (Terms of Service)：大多数网站的服务条款会明确规定是否允许爬取。
# 3. 避免对网站服务器造成过大负担：设置合理的请求间隔（使用 time.sleep()），避免短时间内大量请求。
# 4. 避免抓取敏感或受保护的数据：特别是个人信息。
# 5. 不将抓取到的数据用于非法或不正当竞争的目的。
# 6. 了解并遵守当地的数据保护法律法规。
# --- 声明结束 ---

def scrape_quotes():
   """
   从 quotes.toscrape.com 网站抓取名言和作者信息。
   这是一个为教学目的设计的简单爬虫，仅抓取第一页数据。
   """
   base_url = "http://quotes.toscrape.com"
   quotes_data = [] # 用于存储抓取到的名言和作者信息

   print(f"正在尝试抓取网站: {base_url}")

   try:
       # 1. 发送 HTTP GET 请求获取网页内容
       # 模拟浏览器 User-Agent，可以降低被识别为爬虫的风险
       headers = {
           'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
       }
       response = requests.get(base_url, headers=headers, timeout=10) # 设置请求超时时间为10秒
       response.raise_for_status() # 检查 HTTP 请求是否成功 (状态码 200)

       # 2. 使用 BeautifulSoup 解析 HTML 内容
       soup = BeautifulSoup(response.text, 'html.parser')

       # 3. 查找包含名言的 HTML 元素
       # 观察网站 HTML 结构可知，每条名言都在一个 class 为 'quote' 的 div 标签中
       quote_divs = soup.find_all('div', class_='quote')

       if not quote_divs:
           print("未找到任何名言信息。请检查网站结构是否变化或URL是否正确。")
           return []

       # 4. 遍历每个名言 div，提取名言文本和作者
       for quote_div in quote_divs:
           # 名言文本在 class 为 'text' 的 span 标签中
           text_tag = quote_div.find('span', class_='text')
           # 作者信息在 class 为 'author' 的 small 标签中
           author_tag = quote_div.find('small', class_='author')

           quote_text = text_tag.get_text(strip=True) if text_tag else 'N/A'
           quote_author = author_tag.get_text(strip=True) if author_tag else 'N/A'

           quotes_data.append({
               'text': quote_text,
               'author': quote_author
           })
           print(f"提取到: \"{quote_text}\" - {quote_author}")

       # 5. 为了避免对网站造成压力，每次请求后建议添加延时
       time.sleep(1) # 暂停 1 秒

   except requests.exceptions.RequestException as e:
       print(f"请求失败: {e}")
   except Exception as e:
       print(f"处理网页内容时发生错误: {e}")

   return quotes_data

if __name__ == "__main__":
   # 调用抓取函数
   all_quotes = scrape_quotes()

   print("\n--- 抓取到的所有名言数据 ---")
   if all_quotes:
       for i, quote in enumerate(all_quotes):
           print(f"{i+1}. 名言: {quote['text']}")
           print(f"   作者: {quote['author']}\n")
   else:
       print("没有抓取到任何数据。")
