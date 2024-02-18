import { Zoom } from "react-awesome-reveal";

const InventoryCard = ({ item, dataLength, isSimulationEnd }) => {
  return (
    <Zoom triggerOnce
      className={`flex text-sm rounded-2xl justify-center items-center  border-2 px-5 ${
        isSimulationEnd ? "py-3" : "py-1"
      } shadow flex-shrink-0 ${
        item.day === dataLength && !isSimulationEnd
          ? "bg-[#8884d8]"
          : "bg-[#c9ebe8]"
      }`}
    >
      <div
        className={`p-4 font-medium space-y-[2px] ${
          item.day === dataLength && !isSimulationEnd ? "text-slate-100" : ""
        }`}
      >
        <p>Day : {item.day} </p>
        <p>Inventory Level : {item.InventoryLevel}</p>
        <p>Demand : {item.demand}</p>
        <p>Shortage : {item.Shortage}</p>
        {item?.orderQuantity > 0 && (
          <>
            <div className="pt-2">
              <div
                className={`border-2 ${
                  item.day === dataLength && !isSimulationEnd
                    ? "border-white"
                    : "border-[#8884d8]"
                } px-3 py-2 rounded-lg`}
              >
                <p
                  className={`border-b border-b-[#8884d8] ${
                    item.day === dataLength && !isSimulationEnd
                      ? "border-b-white"
                      : ""
                  }`}
                >
                 {item?.day === 1 ? "Initial" : "" } order {item?.day === 1 ? "" : item.orderCount} { item?.day === 1 ? "was" : "is" } placed
                </p>
                <p>Order Quantity : {item?.orderQuantity}</p>
                <p>Lead-Time: {item?.LeadTime}</p>
              </div>
            </div>
          </>
        )}

        {item.orderDelivered && (
          <div className="pt-2">
            <p
              className={`border-2  px-2 py-1 rounded-lg ${
                item.day === dataLength && !isSimulationEnd
                  ? "border-white"
                  : "border-[#8884d8]"
              }`}
            >
              Order {item.orderCount} is received
            </p>
          </div>
        )}
      </div>
    </Zoom>
  );
};

export default InventoryCard;
