#! /usr/bin/env python

import httplib, urllib
import base64

key = base64.b64encode('python is simple')
value = base64.b64encode('and powerful')
params = urllib.urlencode({
    key: value
    })
headers = {
        "Content-type": "text/tab-separated-values; colenc=B",
        }

conn = httplib.HTTPConnection("10.10.124.143:1978")
conn.request("POST", "/rpc/set", params, headers)
response = conn.getresponse()
print response.status, response.reason
conn.close()
