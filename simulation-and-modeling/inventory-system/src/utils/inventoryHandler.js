const generateRandomDemand = () =>{
    return Math.floor(Math.random()*3 + 1);
}

const generateRandomLeadTime = () =>{
    return Math.floor(Math.random()*2 + 1);
}

export{ generateRandomDemand, generateRandomLeadTime}