class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        q = collections.deque()
        q.append(startUrl)
        seen = set()
        seen.add(startUrl)
        hostname = startUrl[7:].split("/")[0]
        ans = []
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                ans.append(cur)
                nxt_urls = htmlParser.getUrls(cur)
                for nxt_url in nxt_urls:
                    if nxt_url in seen:
                        continue
                    nxt_hostname = nxt_url[7:].split("/")[0]
                    if nxt_hostname != hostname:
                        continue
                    q.append(nxt_url)
                    seen.add(nxt_url)
        return ans