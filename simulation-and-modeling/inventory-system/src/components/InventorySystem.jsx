import { useState, useEffect } from "react";
import {
  generateRandomDemand,
  generateRandomLeadTime,
} from "../utils/inventoryHandler";
import InventoryCard from "./InventoryCard";


const InventorySystem = () => {
  const [inventoryLevel, setInventoryLevel] = useState(3);
  const [day, setDay] = useState(1);
  const [deliveryDate, setDeliveryDate] = useState(2);
  const [leadTime, setLeadTime] = useState(2);
  const [orderQuantity, setOrderQuantity] = useState(8);

  console.log("day = ", day);

  console.log("delivery-date = ", deliveryDate);

  const [shortage, setShortage] = useState(0);
  const [inventoryData, setInventoryData] = useState([]);
  const [ isSimulationEnd, setIsSimulationEnd] = useState(false);

  useEffect(() => {
    const dayInterval = setInterval(() => {
      if (day > 15) {
        setIsSimulationEnd(true);
        clearInterval(dayInterval);
        return;
      }

      const demand = generateRandomDemand();

      let newInventoryLevel = inventoryLevel - demand;

      let isOrderDelivered = day === deliveryDate;
      if (isOrderDelivered) {
        console.log("got it");
      }

      if (day < 5 && isOrderDelivered) {
        newInventoryLevel += 8;
      }

      if (day > 0 && day % 5 === 0) {
        const newLeadTime = generateRandomLeadTime();
        setLeadTime(newLeadTime);
        setDeliveryDate(day + newLeadTime);

        let newToOrder = newInventoryLevel < 0 ? 11 : 11 - newInventoryLevel;
        console.log("new-to-order = ", newToOrder);
        setOrderQuantity(newToOrder);
      }

      if (day >= 5 && isOrderDelivered) {
        console.log("hello i am there");
        newInventoryLevel += orderQuantity;
      }
      // console.log({orderQuantity});
      // console.log({day});

      setInventoryLevel(newInventoryLevel);

      if (newInventoryLevel < 0) {
        let newShortage = newInventoryLevel * -1;
        setShortage(newShortage);
      } else {
        setShortage(0);
      }

      let isOrderDay = day === 1 || day % 5 === 0;

      const newInventoryData = {
        InventoryLevel: inventoryLevel,
        Shortage: shortage,
        demand,
        day,
        leadTime: isOrderDay ? leadTime : 0,
        orderQuantity: isOrderDay ? orderQuantity : 0,
        // orderCount: day === 1 || day % 5 === 0 ? ( Math.floor(day / 5) + 1 ) : 0,
        orderCount: Math.floor(day / 5) + 1,
        orderDelivered: day === deliveryDate + 1,
      };
      setInventoryData((prev) => [...prev, newInventoryData]);
      setDay((prev) => prev + 1);
    }, 3000);

    return () => clearInterval(dayInterval);
  }, [day, inventoryLevel, deliveryDate, orderQuantity, shortage, leadTime]);

  return (
    <>
      <div
        className={`flex gap-3 mx-10 mt-10 ${isSimulationEnd ? "mb-20" : "mb-10"} ${
          day > 15 ? "flex-row overflow-x-auto" : "flex-row-reverse justify-end"
        }`}
      >
        {inventoryData.map((item) => (
          <InventoryCard
            key={item.day}
            item={item}
            dataLength={inventoryData?.length}
            isSimulationEnd={isSimulationEnd}
          ></InventoryCard>
        ))}
      </div>
      

      
    </>
  );
};

export default InventorySystem;
