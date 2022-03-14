import os
from re import L
import shutil

path = r'data\archive'

for folder in os.listdir(path):
    path_alphabet = os.path.join(path, folder)
    for brand in os.listdir(path_alphabet):
        path_brand = os.path.join(path_alphabet, brand)
        print(path_brand)