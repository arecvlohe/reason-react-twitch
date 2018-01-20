open RandomQuotes;

[%bs.raw {|require('./app.css')|}];

let text = ReasonReact.stringToElement;

type state = quote;

type action = Click | NewQuote(quote) | NoOp;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  let generateRandomQuote = (self) => {
    let randomQuote = quotes[randomNumberFromRange(0, 5)];
    self.ReasonReact.send(NewQuote(randomQuote));
  };
  {
  ...component,
  initialState: () => {
    quote: "",
    author: "",
  },
  reducer: (action, _state) => {
    switch action {
    | Click => ReasonReact.SideEffects(generateRandomQuote);
    | NewQuote(quote) => ReasonReact.Update(quote);
    | NoOp => ReasonReact.NoUpdate;
    }
  },
  didMount: (self) => {
    generateRandomQuote(self);
    ReasonReact.NoUpdate;
  },
  render: self =>
    <div className="App">
      <div> (text(self.state.quote))</div>
      <div> (text(self.state.author))</div>
      <button onClick=(_event => self.send(Click))>(text("New Random Quote"))</button>
    </div>
  }
};
