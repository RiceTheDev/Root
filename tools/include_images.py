import os, sys

def prepend(path, text):
    with open(path, 'r') as file:
        original = file.read()
    with open(path, 'w') as file:
        file.write(text + original)

def append(path, text):
    with open(path, 'r') as file:
        original = file.read()
    with open(path, 'w') as file:
        file.write(original + text)

# TODO: Fix this complete mess...
for a, b, c in os.walk("build"):
    for file in c:
        if file.endswith(".h"):
            append("../source/engine/images.h", "#include \"" + file +"\"")
            with open("../source/engine/images.h", 'w') as file:
                lines = file.readlines()
                lines.insert(-2, "{\"" + file + "\", " + file + "}")
            with open("../source/engine/images.h", 'r') as file:
                file.writelines(lines)