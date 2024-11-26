const fs = require('fs');
const process = require('process');

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const k = Number(inputLines[0]);
    const resultArr = inputLines[1].split(" ");
    let tempArr = [];
    tempArr.push(resultArr);
    let idx = 1;
    let limit = Math.pow(2,idx)-1;
    let num = 1;

    while(tempArr.length>0&&limit<=Math.pow(2,k)-1){
        const arr = tempArr.pop();
        const centerIdx = Math.floor(arr.length/2);
        process.stdout.write(arr[centerIdx]);
        process.stdout.write(" ");
        if(centerIdx>0){
            const leftArr = arr.slice(0,centerIdx);
            const rightArr = arr.slice(centerIdx+1);
            tempArr=[rightArr,leftArr,...tempArr];
        }
        if(num>=limit){
            idx+=1;
            limit=Math.pow(2,idx)-1;
            console.log()
        }
        num+=1;
    }
}

main();