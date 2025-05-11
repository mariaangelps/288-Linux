#!/bin/bash

URL="https://finance.yahoo.com/markets/stocks/most-active/"
OUTPUT_FILE="most_active_stocks.html"
#!/bin/bash

URL="https://finance.yahoo.com/markets/stocks/most-active/"
OUTPUT_FILE="most_active_stocks.html"

curl -L "$URL" -o "$OUTPUT_FILE" \
  -H "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36"

echo "Downloaded with spoofed User-Agent to $OUTPUT_FILE"


curl -L "$URL" -o "$OUTPUT_FILE" \
  -H "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36"

echo "Downloaded with spoofed User-Agent to $OUTPUT_FILE"

