import { Slide } from "react-awesome-reveal";
import bank from "../assets/bank-image.jpeg";

const Bank = ({ serviceTaking }) => {
  if(serviceTaking){
    console.log(serviceTaking.id);
  }
  return (
    <div className="w-1/2">
      <img src={bank} alt="bank"/>{" "}
      <Slide key={serviceTaking?.id} delay={300} duration={2000} direction="up">
        <div className={`-mt-64 ml-44 ${serviceTaking.id ? "" : "hidden"}`}>
          <div className="ml-16 -mb-6 rounded-full w-9 py-1.5 text-center bg-green-300 font-bold">
            {serviceTaking?.id}
          </div>
          <img src={serviceTaking?.img} className="w-28 h-28 object-cover object-center shadow-xl shadow-gray-900" alt="Man" />
        </div>
      </Slide>
    </div>
  );
};

export default Bank;
