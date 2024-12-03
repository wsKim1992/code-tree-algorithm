const fs = require("fs");

const dfs = (idx,tree,d,visited)=>{
    const {children} = tree[idx];
    for(let i =0;i<children.length;i++){
        if(!visited[children[i]]){
            visited[children[i]]=true;
            dfs(children[i],tree,d,visited)
            d[idx][1]+=d[children[i]][0];
            d[idx][0]+=d[children[i]][1];
        }
    }
    d[idx][1]+=1;
}

const main = ()=>{
    const inputlines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputlines[0]);
    const tree = Array.from({length:n+1}).map(()=>({children:[]}));
    const visited = Array.from({length:n+1}).map(()=>false);
    const d = Array.from({length:n+1}).map(()=>Array.from({length:2}).map(()=>0));
    inputlines.slice(1).forEach(line=>{
        if(line!==''){
            const [x,y] = line.split(" ").map(Number);
            tree[x].children.push(y)
            tree[y].children.push(x);
        }
    })
    visited[1]=true;
    dfs(1,tree,d,visited);
    console.log(d[1][0]>d[1][1]?d[1][1]:d[1][0])
}

main();