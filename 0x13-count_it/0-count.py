#!/usr/bin/python3

import re
from urllib.parse import urlparse

import requests

"""script for counting keywords in a title of a subreddit"""

api_url = ["https://www.reddit.com/r", "", "hot", ".json"]


def count_words(subreddit, word_list, word_count=None, after="head"):
    """
    recursively process titles of a subreddit then prints the results
    :param subreddit: subreddit or url to subreddit to search
    :param word_list: list of keyword to look for;
     1:1 position match to word_count
    :param word_count: running word count tally;
     1:1 position match to word_list
    :param after: param to used for pagination
     and used as exit clause for recursion if None
    :return: None
    """
    head = False
    if after is None:
        return
    elif after == "head":
        after = None
        head = True

    if not urlparse(subreddit).netloc:
        api_url[1] = subreddit
        subreddit = "/".join(api_url)

    if word_count is None:
        word_count = [0] * len(word_list)
    header = {
        'User-Agent':
            'pythonApp:com.studentProject.countWords:v0.0.1 (by /u/Ostoyae)'
    }
    req = requests.get(
        subreddit, headers=header,
        allow_redirects=False, params={'after': after}
    )
    try:
        req.raise_for_status()
        data = req.json().get('data')
        after = data.get('after')
        count_words(subreddit, word_list, word_count=word_count, after=after)
        process_data(data.get('children'), word_list, word_count)
    except requests.HTTPError as e:
        return

    if head:
        z = dict(zip(word_count, word_list))
        word_count.sort(reverse=True)
        for i in word_count:
            if i > 0:
                print("{}: {}".format(z[i], i))


def process_data(data, word_list, word_count):
    """
    process page data and  count keywords occurrence
    :param data: data to process for keyword
    :param word_list: keyword to search for
    :param word_count: word tally
    :return: None
    """
    for link in data:
        if link['kind'] != 't3':
            continue
        title = link['data']['title']
        for i, word in enumerate(word_list):
            word_count[i] += len(
                re.findall(
                    r"\s" + re.escape(i) + r"(?=\s|$)",
                    title,
                    re.IGNORECASE
                )
            )
