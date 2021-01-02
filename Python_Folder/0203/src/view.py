import matplotlib.pyplot as plt
from jieba import analyse
from wordcloud import WordCloud

text = open(r'./0203/data/疯狂原始人2.csv', "r", encoding='utf-8').read()
tags = analyse.extract_tags(text,  topK=50, withWeight=False)
new_text = ' '.join(tags)
stopwords = set('')

stopwords.update(['疯狂','原始', ',', '一个', '这样', '还是', '2020-12-25', '人', '觉得', '动画', '推荐', '力荐', '还行'])
wc = WordCloud(
    font_path="./0203/img/font.ttc",
    background_color="white",
    mask=plt.imread(
        "./0203/img/map.jpeg"),
    max_words=200,
    width=768,
    stopwords=stopwords,
    height=1024,

).generate(new_text)
plt.imshow(wc, cmap='rainbow', interpolation='bilinear')
plt.figure('db.wordcloud')
plt.axis('off')
wc.to_file('./0203/img/cloud.png')
