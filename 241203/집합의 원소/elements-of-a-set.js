const fs = require("fs");

const find = (uf,idx)=>{
    if(uf[idx]===idx)return idx;
    const rootNode = find(uf,uf[idx]);
    uf[idx]=rootNode;
    return rootNode;
}

const union = (uf,fr,to)=>{
    const frRoot = find(uf,fr);
    const toRoot = find(uf,to);
    if(frRoot!==toRoot)uf[frRoot]=toRoot;
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const [n,m] = inputLines[0].split(" ").map(Number);
    const uf = Array.from({length:n+1}).map((_,idx)=>idx);
    inputLines.slice(1).forEach(line=>{
        if(line!==""){
            const [sign,a,b] =line.split(" ").map(Number);
            if(sign===0){
                union(uf,a,b);
            }else if(sign===1){
                const aRoot = find(uf,a);
                const bRoot = find(uf,b);
                console.log(Number(aRoot===bRoot));
            }
        }
    })
}


main();