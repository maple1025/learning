var fs = require('fs'),
    oldFilename,
    newFilename,
    isSymLink;

oldFilename = "./processId.txt";
newFilename = "./processIdNew.txt";

fs.chmodSync(oldFilename, 777);
fs.renameSync(oldFilename, newFilename);

isSymLink = fs.lstatSync(newFilename).isSymbolicLink();
