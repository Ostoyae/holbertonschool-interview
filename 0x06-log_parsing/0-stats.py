#!/usr/bin/python3
''' program for parsing a line'''

import cmd
import sys
import signal


class LineParser:
    ''' Define method for parsing'''

    @staticmethod
    def parse_line(line):
        data_slice = line.split(" ")[7:9]
        return (int(data_slice[0]), int(data_slice[1]))


class StateCode:
    ''' Define class for reading lines form stdin'''

    _buf_size = 512
    _file_size = 0
    _read_iter = 0
    _status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def process(self, line):
        '''
        handles each `line`
        '''

        self._read_iter += 1
        (status, length) = LineParser.parse_line(line)
        self._file_size += length
        self._status[status] += 1

        if self._read_iter % 10 == 0:
            print(f"File size: {self._file_size}")
            for (k, v) in self._status.items():
                if v > 0:
                    print(f"{k}: {v}")

    def loop(self):
        '''
        looping body of the application
        '''

        def signal_handel(sig, frame):
            sc = ""
            for (k, v) in self._status.items():
                if v > 0:
                    sc += f"{k}: {v}\n"

            print(f"File size: {self._file_size}\n{sc}", sep="")

            raise KeyboardInterrupt

        signal.signal(signal.SIGINT, signal_handel)
        with sys.stdin as reader:
            while True:
                line = reader.readline(self._buf_size)[1:]
                if (len(line) > 0):
                    self.process(line)


if __name__ == "__main__":
    StateCode().loop()
