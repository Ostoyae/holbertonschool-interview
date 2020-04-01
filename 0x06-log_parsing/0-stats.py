#!/usr/bin/python3
""" 0x06 log parsing This program will parse each line."""


class LineParser:
    """Define method for parsing
    """

    @staticmethod
    def parse_line(line):
        """ Returns tuple of status code and size
        Method that parses line
        """
        try:
            data_slice = line.split(" ")[7:9]
            return int(data_slice[0]), int(data_slice[1])
        except IndexError:
            pass

        return 0, 0


if __name__ == "__main__":
    import sys

    buf_size = 512
    file_size = 0
    read_iter = 0
    status_code = {200: 0, 301: 0, 400: 0,
                   401: 0, 403: 0, 404: 0,
                   405: 0, 500: 0}

    with sys.stdin as reader:
        try:
            while True:
                line = reader.readline(buf_size)
                if len(line) > 2:
                    (status, length) = LineParser.parse_line(line)
                    file_size += length
                    if status in status_code.keys():
                        read_iter += 1
                        status_code[status] += 1

                    if read_iter % 10 == 0:
                        print("File size: {}".format(file_size))
                        for (k, v) in status_code.items():
                            if v > 0:
                                print("{}: {}".format(k, v))
        except KeyboardInterrupt:
            sc = ""
            for (k, v) in status_code.items():
                if v > 0:
                    sc += "{key}: {val}\n".format(key=k, val=v)

            print("File size: {}\n{}".format(file_size, sc, sep=""))
