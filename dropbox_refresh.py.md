---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://api.dropbox.com/oauth2/token
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nimport requests\n\n# Fetch environment variables\nDROPBOX_REFRESH_TOKEN\
    \ = os.getenv('DROPBOX_REFRESH_TOKEN')\nDROPBOX_APP_KEY = os.getenv('DROPBOX_APP_KEY')\n\
    DROPBOX_APP_SECRET = os.getenv('DROPBOX_APP_SECRET')\n\n# Dropbox API URL for\
    \ token refresh\nurl = \"https://api.dropbox.com/oauth2/token\"\n\n# Prepare the\
    \ data for the POST request\ndata = {\n    'refresh_token': DROPBOX_REFRESH_TOKEN,\n\
    \    'grant_type': 'refresh_token',\n    'client_id': DROPBOX_APP_KEY,\n    'client_secret':\
    \ DROPBOX_APP_SECRET\n}\n\n# Make the POST request\nresponse = requests.post(url,\
    \ data=data)\n\n# Check for success and print the result\nif response.status_code\
    \ == 200:\n    DROPBOX_ACCESS_TOKEN = response.json().get('access_token')\n  \
    \  print(f\"new dropbox access token : {DROPBOX_ACCESS_TOKEN}\")\n\n\nelse:\n\
    \    print(\"Error:\", response.status_code, response.text)\n"
  dependsOn: []
  isVerificationFile: false
  path: dropbox_refresh.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dropbox_refresh.py
layout: document
redirect_from:
- /library/dropbox_refresh.py
- /library/dropbox_refresh.py.html
title: dropbox_refresh.py
---
