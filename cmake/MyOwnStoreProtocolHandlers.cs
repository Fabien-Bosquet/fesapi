using System;

using F2iConsulting.Fesapi.Energistics.Etp.v12.Datatypes.Object;
using F2iConsulting.Fesapi.Energistics.Etp.v12.Protocol.Store;
using F2iConsulting.Fesapi.${FESAPI_ETP_NS};

public class MyOwnStoreProtocolHandlers : StoreHandlers
{
    public MyOwnStoreProtocolHandlers(AbstractSession mySession)
        : base(mySession)
    {
    }

    public override void on_GetDataObjectsResponse(GetDataObjectsResponse msg, long correlationId)
    {
        foreach (DataObject dataObj in msg.dataObjects.Values)
        {
            Console.WriteLine("*************************************************");
            Console.WriteLine("Resource received : ");
            Console.WriteLine("uri : " + dataObj.resource.uri);
            Console.WriteLine("datatype : " + dataObj.resource.dataObjectType);
            Console.WriteLine("name : " + dataObj.resource.name);
            Console.WriteLine("xml : " + dataObj.data);
            Console.WriteLine("*************************************************");
        }

        Console.WriteLine("Asking to close");
        getSession().close();
    }
}
