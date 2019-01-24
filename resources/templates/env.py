#   == IMPORTS ==
import os


#   == CONSTANTS ==
#   -- Environment Variables --
try:
    PROJECTS_DIR = os.environ["PROJECTS_DIR"]
except KeyError:
    print("Please set the environment variable PROJECTS_DIR")
    exit()

try:
    ARCTK_DIR = os.environ["ARCTK_DIR"]
except KeyError:
    print("Please set the environment variable ARCTK_DIR")
    exit()
