#   == IMPORTS ==
from args import get_namespace_list


#   == FUNCTIONS ==
#   -- Formatting --
def indent(level_):
    indentation = ""
    for i in range(level_):
        indentation += " "
    return (indentation)


def get_namespaces_open():
    namespace_list = get_namespace_list()
    opener = ""
    for i in range(len(namespace_list)):
        indentation = indent(4 * i)
        opener += indentation + "namespace " + namespace_list[i] + "\n"
        opener += indentation + "{"
        if i != (len(namespace_list) - 1):
            opener += "\n"
    return (opener)


def get_namespaces_close():
    namespace_list = get_namespace_list()
    closer = ""
    for i in range(len(namespace_list) - 1, -1, -1):
        indentation = indent(4 * i)
        closer += indentation + "} // namespace " + namespace_list[i]
        if i != 0:
            closer += "\n"
    return (closer)


def get_namespace_indent():
    return (indent(4 * len(get_namespace_list())))
