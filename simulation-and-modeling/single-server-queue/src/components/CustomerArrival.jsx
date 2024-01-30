import { useState, useEffect } from "react";

import Bank from "./Bank";
import CompletedCustomer from "./CompletedCustomer";
import CustomerQueue from "./CustomerQueue";
import man from "../assets/man.png";
import man2 from "../assets/man2.png";
import man3 from "../assets/man3.png";
import man4 from "../assets/man4.png";

export function CustomerArrival() {
  const [queue, setQueue] = useState([]);

  const [completed, setCompleted] = useState([]);
  const [isServerBusy, setIsServerBusy] = useState(false);

  const [idHandler, setIdHandler] = useState(1);

  const [serviceTaking, setServiceTaking] = useState({});
  // (Math.floor(Math.random()*1000) + 2000)

  useEffect(() => {
    const mans = [man, man2, man3, man4];
    const arriveInterval = setInterval(() => {
      // Add new customer to queue
      setQueue((prev) => [
        ...prev,
        {
          // id: Date.now(),
          // id: queue.length + completed.length + 1,
          id: idHandler,

          arriveTime: new Date(),
          img: mans[Math.floor(Math.random() * 4)],
          // serviceTime: 1000 + Math.floor(Math.random() * 7000)
          serviceTime: Math.floor(Math.random() * 5000) + 4000,
        },
      ]);
      setIdHandler((prev) => prev + 1);
    }, Math.floor(Math.random() * 5000));

    return () => clearInterval(arriveInterval);
  }, [idHandler]);

  useEffect(() => {
    if (!isServerBusy && queue.length > 0) {
      setIsServerBusy(true);

      const currentCustomer = queue[0];

      setServiceTaking(currentCustomer);
      setQueue((prevQueue) => prevQueue.slice(1));
      const servedTime = new Date();

      const waitingTime = parseInt((servedTime - currentCustomer.arriveTime) / 1000);

      setTimeout(() => {
        setCompleted((prevCompleted) => [
          ...prevCompleted,
          { ...currentCustomer, waitingTime, servedTime },
        ]);

        // console.log(currentCustomer.id, waitingTime);
        // console.log(
        //   currentCustomer?.arriveTime?.toLocaleTimeString(),
        //   " served time ",
        //   servedTime?.toLocaleTimeString()
        // );

        // const remainingCustomers = queue.slice(1);
        // setQueue(remainingCustomers);
        // setQueue((prevQueue) => prevQueue.slice(1));
        setIsServerBusy(false);
      }, currentCustomer.serviceTime);

      // return () => clearTimeout(timeOutId);
    }
  }, [isServerBusy, queue]);

  return (
    <div className="flex gap-10 px-32 pt-16">
      <CustomerQueue queue={queue}></CustomerQueue>
      <Bank isServerBusy={isServerBusy} serviceTaking={serviceTaking}></Bank>

      <CompletedCustomer queue={completed}></CompletedCustomer>
    </div>
  );
}
