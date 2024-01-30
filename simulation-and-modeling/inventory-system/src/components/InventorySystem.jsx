import { useState, useEffect } from "react";
import { generateRandomDemand } from "../utils/inventoryHandler";

const InventorySystem = () => {
  const [inventoryLevel, setInventoryLevel] = useState(5);
  const [ leadTime, setLeadTime ] = useState(0);
  // const [ orderProcessing, setOrderProcessing ] = useState(false);
  // const [ toOrder, setToOrder ] = useState(0);
  console.log(leadTime);
  const [shortage, setShortage] = useState(0);
  const [inventoryData, setInventoryData] = useState([]);

  useEffect(() => {
  const dayInterval =  setInterval(() => {
    const demand = generateRandomDemand()
    
    let newInventoryLevel = inventoryLevel - demand;
    // let order = 0;

    if(newInventoryLevel < 3){
      // setOrderProcessing(true);
      // order = inventoryLevel <= 0 ? 12 : 12 - newInventoryLevel;
      // setToOrder(newOrder);
      if(leadTime == 3){
        newInventoryLevel += 12;
        // setOrderProcessing(false);
      }
        setLeadTime( prev => prev + 1)
    }
    else{
      setLeadTime(0);
      // setOrderProcessing(false);
      
      // setToOrder(0);
    }
    setInventoryLevel(newInventoryLevel);
    if(newInventoryLevel < 0){
     let newShortage = (newInventoryLevel * -1);
      setShortage(newShortage)
    }
    else{
      setShortage(0)
    }

    const newInventoryData = {id: Date.now(), inventoryLevel, shortage, demand};
    setInventoryData(prev => [...prev, newInventoryData])

   }, 5000);

   return () => clearInterval(dayInterval)
  }, [inventoryLevel, leadTime,shortage]);

  return <div>
    {
      inventoryData.map( item => <div key={item.id} className="flex gap-5">
        {/* <p>{item.id}</p> */}
        <p>Inventory Level : {item.inventoryLevel}</p>
        <p>Demand : {item.demand}</p>
        {/* <p>To Order : { item.order} </p> */}
        {/* <p>{item.shortage}</p> */}
      </div>)
    }
  </div>
};

export default InventorySystem;
