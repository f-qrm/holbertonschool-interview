# Log Parsing

## Description
Script that reads stdin line by line and computes metrics from HTTP log entries.

## Input format
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```
Lines that don't match this format are skipped.

## Output
Printed after every 10 valid lines and on keyboard interrupt (CTRL+C):
```
File size: <total size>
<status code>: <count>
...
```
Valid status codes: `200`, `301`, `400`, `401`, `403`, `404`, `405`, `500` (printed in ascending order, only if they appear).

## Usage
```
./0-generator.py | ./0-stats.py
```
