import os
import subprocess

BLOCK_MAX_CNT = 4
PAGE_MAX_CNT = 4

def main():
    path = os.path.dirname(os.path.realpath(__file__))
    with open(path + "/src/inc/file_names.h", "w") as hfile:
        hfile.write("/**************************************************************\n")
        hfile.write("This is a auto-generated file. Please run the following command\n")
        hfile.write("               python3 file_generator.py                       \n")
        hfile.write("**************************************************************/\n")
        hfile.write("\n#pragma once")
        hfile.write("\n#pragma GCC diagnostic ignored \"-Wunused-variable\"")
        hfile.write(f"\n\n#define BLOCK_MAX_CNT        ({BLOCK_MAX_CNT})")
        hfile.write(f"\n#define PAGE_MAX_CNT         ({PAGE_MAX_CNT})")
        hfile.write("\n\nstatic char gFileNames[BLOCK_MAX_CNT][PAGE_MAX_CNT][256] = ")
        hfile.write("\n{")

        maindir = path + "/file_stack/"
        for i in range(0, BLOCK_MAX_CNT):
            hfile.write("\n\t{")
            blockdir = f"file_block_{hex(i)}"
            for j in range(0, PAGE_MAX_CNT):
                file_name = maindir + blockdir + f"/file_unit_{hex(j)}.bin"
                hfile.write(f"\n\t\t\"{file_name}\",")
                subprocess.run(["mkdir", f"{maindir}{blockdir}"], stderr=subprocess.DEVNULL)
                open(file_name, "wb")
            hfile.write("\n\t},")
        hfile.write("\n};")



if __name__ == "__main__":
    main()