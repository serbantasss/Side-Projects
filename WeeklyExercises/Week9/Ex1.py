def removecomments(infile, outfile, force = False):
    if force == True:
        mod = 'w'
    else:
        mod = 'x'
    with open(infile, 'r') as fin, open(outfile, mod) as fout:
          lines = fin.readlines()
          for line in lines:
             fout.write(line.replace('[','{').replace(']','}'))

infile="inputraw.txt"
outfile="inputvalid.txt"
removecomments(infile, outfile, True)
print(f"file {infile} filtered, output is in {outfile}")