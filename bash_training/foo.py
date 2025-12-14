#!/usr/bin/env python3
import os


def print_os() -> None:
    p_os = os.uname()
    os_name = os.uname().machine()
    print(p_os)


if __name__ == "__main__":
    print_os()
