#   == IMPORTS ==
import sys


#   == FUNCTIONS ==
#   -- Command Line Arguments --
def validate_args():
    if len(sys.argv) < 2:
        print("Error! Not enough namespaces.")
        exit()


def get_path():
    validate_args()
    args = sys.argv.copy()
    args.pop(0)
    args.pop(0)
    path = ""
    for i in range(len(args)):
        if i != 0:
            path += "/"
        path += args[i].lower()
    return (path)


def get_namespace_list():
    validate_args()
    namespaces = sys.argv.copy()
    namespaces.pop(0)
    namespaces.pop(-1)
    for i in range(len(namespaces)):
        namespaces[i] = namespaces[i].lower()
    return (namespaces)


def get_class_name():
    validate_args()
    return (sys.argv[-1].title())


def get_structure_name():
    validate_args()
    return (sys.argv[-1].lower())
