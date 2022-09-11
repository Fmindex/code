import hashlib
import sys

def permuteString( org ):
  if len(org) == 1:
    return permuteChar(org[0])
  tmp = permuteChar(org[0])
  strs = []
  for s1 in tmp:
    for s2 in permuteString(org[1:]):
      strs.append(s1 + s2)
  return strs

def permuteChar(ch):
  if ch == "i":
    return ("i", "I", "1")
  if ch == "l":
    return ("l", "L", "1")
  if ch == "o":
    return ("o", "O", "0")
  if ch.isalpha():
    return (ch.lower(), ch.upper())
  return ch

if len(sys.argv) < 2:
  print("Usage : " + sys.argv[0] + " hash_value")

hashpwd = sys.argv[1]

f = open("10k_most_common.txt", "r")
found = False
while not found:
  txt = f.readline().strip()
  if txt == "":
    break
  tryMe = permuteString(txt)
  for pwd in tryMe:
    trypwd = hashlib.sha1(pwd.encode()).hexdigest()
    if trypwd == hashpwd:
      print("Found : " + pwd)
      found = True
      break
f.close()
print("Done")