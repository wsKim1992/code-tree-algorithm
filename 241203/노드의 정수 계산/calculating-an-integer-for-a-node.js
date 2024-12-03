const fs = require("fs");

const dfs = (idx,tree,d,value)=>{
    let sum = value;
    const {children} = tree[idx];
    children.forEach(child=>{
        const {idx:childIdx,value} = child;
        const result = dfs(childIdx,tree,d,value);
        sum+=result;
    })
    d[idx]=sum;
    return d[idx]>0?sum:0;
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const tree = Array.from({length:n+1}).map(()=>({children:[]}));
    const d = Array.from({length:n+1}).map(()=>0);
    inputLines.slice(1).forEach((line,idx)=>{
        if(line!==""){
            const [t,a,p] = line.split(" ").map(Number);
            const actualIdx = idx+2;
            tree[p].children.push({idx:actualIdx,value:t===0?(0-a):a});
        }
    })
    dfs(1,tree,d,0);
    console.log(d[1]);
}

main();