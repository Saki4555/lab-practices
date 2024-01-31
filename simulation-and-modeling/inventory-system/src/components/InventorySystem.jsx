import { useState, useEffect } from "react";
import {
  generateRandomDemand,
  generateRandomLeadTime,
} from "../utils/inventoryHandler";
import InventoryBarChart from "./InventoryBarChart";
import InventoryCard from "./InventoryCard";

const InventorySystem = () => {
  const [inventoryLevel, setInventoryLevel] = useState(3);
  const [leadTime, setLeadTime] = useState(2);

  const [day, setDay] = useState(1);

  // const [ orderQuantity, setOrderQuantity ] = useState(0);
  // console.log("order-quantity = ",orderQuantity);

  console.log("day = ", day);

  console.log("leadtime = ", leadTime);

  const [shortage, setShortage] = useState(0);
  const [inventoryData, setInventoryData] = useState([]);

  useEffect(() => {
    const dayInterval = setInterval(() => {

      if(day > 15){
        clearInterval(dayInterval);
        return;
      }
      const demand = generateRandomDemand();

      let newInventoryLevel = inventoryLevel - demand;

      if(day < 5 && day == leadTime){
        newInventoryLevel += 8;
      }

      if (day > 0 && day % 5 === 0) {
        setLeadTime(day + generateRandomLeadTime());

        //  setOrderQuantity(newToOrder);

        // if( newInventoryLevel < 0 ){
        //   newToOrder = 11;
        // }
        // else{
        //   newToOrder = 11 - newInventoryLevel;
        // }
      }

      if (day > 5 && day === leadTime) {
        console.log("hello i am there");

        let newToOrder = newInventoryLevel < 0 ? 11 : 11 - newInventoryLevel;

        newInventoryLevel += newToOrder;
        console.log("new-to-order = ", newToOrder);
      }

      // if(newInventoryLevel < 3){

      //   if(leadTime == 3){
      //     newInventoryLevel += 12;

      //   }
      //     setLeadTime( prev => prev + 1)
      // }
      // else{
      //   setLeadTime(0);
      // }
      setInventoryLevel(newInventoryLevel);
      if (newInventoryLevel < 0) {
        let newShortage = newInventoryLevel * -1;
        setShortage(newShortage);
      } else {
        setShortage(0);
      }

      const newInventoryData = {
        inventoryLevel,
        shortage,
        demand,
        day,
      };
      setInventoryData((prev) => [...prev, newInventoryData]);
      setDay((prev) => prev + 1);
    }, 500);

    return () => clearInterval(dayInterval);
  }, [day, inventoryLevel, leadTime, shortage]);

  return (
   
    <>

    
     <div className={`flex gap-3 m-10 mb-20 ${day > 15 ? "flex-row overflow-x-auto" : "flex-row-reverse justify-end"}`}>
      {inventoryData.map((item) => (
        <InventoryCard key={item.day} item={item} dataLength={inventoryData?.length}></InventoryCard>
      ))}
    </div>
     
   
    {
      inventoryData.length > 0 && <InventoryBarChart inventoryData={inventoryData}></InventoryBarChart>
    }
    
   </>
  );
};

export default InventorySystem;
