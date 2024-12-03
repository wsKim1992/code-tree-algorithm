const fs = require("fs");

const result = [];

const getResult = (l,r,l1,r1,preorder,inorder)=>{
    if(l>r)return;
    if(l===r){
        result[result.length]=preorder[l];
        return;
    }
    const rootNode = preorder[l];
    const rootIdx = inorder.findIndex(v=>v===rootNode);
    const leftSize = rootIdx-l1;
    getResult(l+1,l+leftSize,l1,rootIdx-1,preorder,inorder);
    getResult(l+leftSize+1,r,rootIdx+1,r1,preorder,inorder);
    result[result.length]=rootNode;
}

const main = ()=>{
    const inputLines= fs.readFileSync(0).toString().split('\n');
    const n = Number(inputLines[0]);
    const preorder = Array.from({length:n+1}).map(()=>-1);
    const inorder = Array.from({length:n+1}).map(()=>-1);
    inputLines[1].split(" ").forEach((v,idx)=>{
        preorder[idx+1]=v;
    });
    inputLines[2].split(" ").forEach((v,idx)=>{
        inorder[idx+1]=v;
    })
    getResult(1,n,1,n,preorder,inorder)
    console.log(result.join(" "))
}

main();