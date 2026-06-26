#!/usr/bin/python3
"""Log parsing script that reads stdin line by line and computes metrics."""
import sys
import re


def print_stats(total_size, status_counts):
    """Print current statistics to stdout."""
    print("File size: {}".format(total_size))
    # Affiche les codes dans l'ordre croissant, seulement s'ils sont > 0
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def main():
    """Read stdin line by line and compute log metrics."""
    total_size = 0
    line_count = 0
    valid_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    status_counts = {code: 0 for code in valid_codes}

    # Format attendu :
    # <IP> - [<date>] "GET /projects/260 HTTP/1.1" <status> <size>
    pattern = re.compile(
        r'^\d+\.\d+\.\d+\.\d+ - \[.+\] '
        r'"GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
    )

    try:
        for line in sys.stdin:
            match = pattern.match(line.strip())
            if not match:
                # Ligne au mauvais format : on l'ignore
                continue

            status = int(match.group(1))
            file_size = int(match.group(2))

            total_size += file_size
            if status in valid_codes:
                status_counts[status] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        # EOF : afficher les lignes restantes si le dernier bloc < 10
        if line_count % 10 != 0:
            print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        # Afficher les stats au CTRL+C, puis laisser l'exception remonter
        print_stats(total_size, status_counts)
        raise


if __name__ == "__main__":
    main()
