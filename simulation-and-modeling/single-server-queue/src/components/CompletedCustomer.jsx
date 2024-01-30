import { Fade, Slide } from "react-awesome-reveal";

const CompletedCustomer = ({ queue }) => {
  
  return (
    <div className="w-1/3 border flex justify-center bg-[#d7dfde]">
      <div>
        <Fade cascade className="text-xl font-bold pt-5">
          Completed Customers
        </Fade>
        <div>
          {queue.map((customer) => (
            <>
              <Fade key={customer.id} className="my-10">
                <div className="flex">
                  {/* flex gap-3 */}
                  <div className="flex items-center mt-4">
                    <div className="text-[12px]">
                    {/* <p className="font-semibold">
                        Starting Time : {" "}
                        {customer?.servedTime.toLocaleTimeString()}
                      </p> */}
                      <p className="font-semibold">
                        Waiting Time : {" "}
                        {customer?.waitingTime}
                      </p>
                      <p className="font-semibold">
                        Service Time : {parseInt(customer.serviceTime / 1000)}
                      </p>
                    </div>
                  </div>
                  <div className="">
                    <Slide
                     direction="left"
                      key={customer.id}
                      className="ml-11 -mb-6 rounded-full w-9 py-1.5 text-center text-black font-bold bg-green-300"
                    >
                      {customer.id}
                    </Slide>
                    <img
                      src={customer.img}
                      alt="Man"
                      className="w-20 h-20 object-cover object-center"
                    />
                  </div>
                </div>
              </Fade>
              {/* <hr className="bg-red-400 h-1"/> */}
            </>
          ))}
        </div>
      </div>
    </div>
  );
};

export default CompletedCustomer;
