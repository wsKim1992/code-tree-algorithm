const fs = require("fs");

const initializeDepth = (idx,tree,visited,depth,depthValue)=>{
    const children = tree[idx];
    depth[idx]=depthValue;
    for(let i=0;i<children.length;i++){
        if(visited[children[i]])continue;
        visited[children[i]]=true;
        initializeDepth(children[i],tree,visited,depth,depth[idx]+1);
    }
}


const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const tree = Array.from({length:n+1}).map(()=>[]);
    const visited = Array.from({length:n+1}).map(()=>false);
    const parent = Array.from({length:n+1}).map(()=>-1);
    const depth = Array.from({length:n+1}).map(()=>0);
    inputLines.slice(1,n).forEach(line=>{
        if(line!==""){
            const [x,y] = line.split(" ").map(Number);
            tree[x].push(y);
            parent[y]=x;            
        }
    })
    const rootNode = parent.findLastIndex(v=>v===-1);
    visited[rootNode]=true;
    initializeDepth(rootNode,tree,visited,depth,0);
    let [fr,to] = inputLines[n].split(" ").map(Number);
    let [a,b] = depth[fr]>depth[to]?[fr,to]:[to,fr];
    while(depth[a]!==depth[b]){
        a=parent[a];
    }
    while(a!=b){
        a=parent[a];
        b=parent[b];
    }
    console.log(a);
}

main();