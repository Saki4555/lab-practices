import { Fade, Slide } from "react-awesome-reveal";

const CustomerQueue = ({ queue }) => {
  return (
    <div className="w-1/3 border flex justify-center bg-[#d0f4ea]">
      <div>
        <Fade cascade className="text-xl font-bold pt-5">Customer Queue</Fade>
        <div>
          {queue.map((customer) => (
            <>
              <Fade key={customer.id} className="my-10">
                <div className="flex">
                  <div className="">
                    <Slide
                    direction="right"
                      key={customer.id}
                      className="ml-11 -mb-6 rounded-full w-9 py-1.5 text-center text-black bg-green-300 font-bold"
                    >
                      {customer.id}
                    </Slide>
                    <img
                      src={customer.img}
                      alt="Man"
                      className="w-20 h-20 object-cover object-center"
                    />
                  </div>
                  {/* flex gap-3 */}
                  <div className="flex items-center mt-4">
                    <div className="text-[13px]">
                      <p className="font-semibold">
                        Arrival Time :{" "}
                        {customer.arriveTime.toLocaleTimeString()}
                      </p>
                      {/* <p className="font-semibold">
                        Service Time : {parseInt(customer.serviceTime / 1000)}
                      </p> */}
                    </div>
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

export default CustomerQueue;
