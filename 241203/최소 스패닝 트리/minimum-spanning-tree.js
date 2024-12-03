const fs = require("fs");

const find = (uf,idx)=>{
    if(uf[idx]===idx)return idx;
    return uf[idx]=find(uf,uf[idx]);
}

const union = (uf,fr,to)=>{
    const frRoot = find(uf,fr);
    const toRoot = find(uf,to);
    uf[frRoot]=toRoot;
}

const main = ()=>{
    const inputlines = fs.readFileSync(0).toString().split("\n");
    const [n,m] = inputlines[0].split(" ").map(Number);
    const edges = Array.from({length:m}).map(()=>({fr:-1,to:-1,w:-1}));
    const uf = Array.from({length:n+1}).map((_,idx)=>idx);
    inputlines.slice(1).forEach((line,idx)=>{
        if(line!==""){
            const [a,b,w] = line.split(" ").map(Number)
            edges[idx]={fr:a,to:b,w};
        }
    })
    const sortedEdges = edges.sort((a,b)=>a.w-b.w);
    let ans=0;
    while(sortedEdges.length>0){
        const edge = sortedEdges.shift();
        const {fr,to,w} = edge;
        const frRoot = find(uf,fr);
        const toRoot = find(uf,to);
        if(frRoot!==toRoot){
            union(uf,fr,to);
            ans+=w;
        }
    }
    console.log(ans)
}

main();