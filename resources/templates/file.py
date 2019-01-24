#   == IMPORTS ==
import os


#   == FUNCTIONS ==
#   -- File --
def get_contents(path_):
    if not os.path.isfile(path_):
        print("Error! File:", path_, "does not exist.")
        exit()
    with open(path_) as file:
        return (file.read())


def create_file(path_):
    if os.path.isfile(path_):
        print("Error! File:", path_, "already exists.")
        exit()
    if not os.path.exists(os.path.dirname(path_)):
        os.makedirs(os.path.dirname(path_))
    file = open(path_, "w")
    return (file)


def write_file(path_, str_):
    file = create_file(path_)
    file.write(str_)


def indent(file, depth_, str_=""):
    for i in range(depth_):
        file.write(" ")
    file.write(str_)


#   -- Environment Variables --
try:
    ARCTK_DIR = os.environ["ARCTK_DIR"]
except KeyError:
    print("Please set the environment variable ARCTK_DIR")
    exit()
